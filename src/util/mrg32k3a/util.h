/*
 *  util.h
 *  
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/7/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef UTIL_H
#define UTIL_H


/** Some defines to spare constant memory... */
#define        m1         4294967087.0   // 2^32 - 209
#define        m2         4294944443.0   // 2^32 - 22853
#define        norm       1.0 / (m1 + 1.0)
#define        a12        1403580.0       // a1_2
#define        a13n       810728.0        // -a1_3
#define        a21        527612.0        //  a2_1 
#define        a23n       1370589.0       // -a2_3
#define        two17      131072.0        // 2^17
#define        two53      9007199254740992.0 // 2^53
#define        fact       5.9604644775390625e-8f     /* 1 / 2^24  */

#define        MATRIX_ROW     3
#define        MATRIX_COLUMN  3


/** The following functions are used on both host and device sides
    they are marked inlined so that utils.h can be included
    in several compilation units without any linking problem.
*/


namespace shoverand {
	namespace util {
		namespace mrg32k3a {
		
		/** This structure owns static methods implied in random number computation.
		 * They are basically dedicated to matrix calculi.
		 * 
		 * \author jH@CKtheRipper
		 */
		struct Math {
			
			/**
			* Return (a*s + c) MOD m; a, s, c and m must be < 2^35
			*  \author Pierre L'Ecuyer
			*/
			__host__ __device__
			static double MultModM (double a, double s, double c, double m)
			{
				double v;
				long a1;
				
				v = a * s + c;
				
				if (v >= two53 || v <= -two53) {
					a1 = static_cast<long> (a / two17); 
					a -= a1 * two17;
					
					v  = a1 * s;
					
					a1 = static_cast<long> (v / m);
					v -= a1 * m;
					
					v = v * two17 + a * s + c;
				}
				
				a1 = static_cast<long> (v / m);
				
				/* in case v < 0)*/
				if ((v -= a1 * m) < 0.0)    return v += m;   
				else                        return v;
			}


			/**
			* Compute the vector v = A*s MOD m. Assume that -m < s[i] < m.
			* Works also when v = s.
			*  \author Pierre L'Ecuyer
			*/
			__host__ __device__
			static void MatVecModM (const double A[3][3], const double s[3], double v[3],
								double m)
			{
				int i;
				double x[3];               // Necessary if v = s
				
				for (i = 0; i < 3; ++i) {
					x[i] = MultModM (A[i][0], s[0], 0.0, m);
					x[i] = MultModM (A[i][1], s[1], x[i], m);
					x[i] = MultModM (A[i][2], s[2], x[i], m);
				}
				for (i = 0; i < 3; ++i)
					v[i] = x[i];
			}


			/**
			* Compute the matrix C = A*B MOD m. Assume that -m < s[i] < m.
			* Note: works also if A = C or B = C or A = B = C.
			*  \author Pierre L'Ecuyer
			*/
			__host__ __device__
			static void MatMatModM (const double A[3][3], const double B[3][3],
								double C[3][3], double m)
			{
				int i, j;
				double V[3], W[3][3];
				
				for (i = 0; i < 3; ++i) {
					for (j = 0; j < 3; ++j)
						V[j] = B[j][i];
					MatVecModM (A, V, V, m);
					for (j = 0; j < 3; ++j)
						W[j][i] = V[j];
				}
				for (i = 0; i < 3; ++i)
					for (j = 0; j < 3; ++j)
						C[i][j] = W[i][j];
			}

			__device__
			static void MatVecModM_device (double* A, const double s[3], double v[3],
								double m)
			{
				int i;
				double x[3];               // Necessary if v = s
				
				for (i = 0; i < 3; ++i) {
					x[i] = MultModM (A[i*MATRIX_ROW + 0], s[0], 0.0, m);
					x[i] = MultModM (A[i*MATRIX_ROW + 1], s[1], x[i], m);
					x[i] = MultModM (A[i*MATRIX_ROW + 2], s[2], x[i], m);
				}
				for (i = 0; i < 3; ++i)
					v[i] = x[i];
			}


			__device__
			static void MatPowModM (double* A,  double B[3][3], double m, long n)
			{
				int i, j;
				double W[3][3];

				/* initialize: W = A; B = I */
				for (i = 0; i < 3; ++i)
					for (j = 0; j < 3; ++j) {
							W[i][j] = *(A + i * MATRIX_COLUMN + j);
							B[i][j] = 0.0;
					}
				for (j = 0; j < 3; ++j)
					B[j][j] = 1.0;

				/* Compute B = A^n mod m using the binary decomposition of n */
				while (n > 0) {
					if (n % 2) MatMatModM (W, B, B, m);
					MatMatModM (W, W, W, m);
					n /= 2;
				}
			}

			/**
			* Compute the matrix B = (A^(2^e) Mod m);  works also if A = B. 
			*
			*  \author Pierre L'Ecuyer
			*/
			__host__
			static void MatTwoPowModM (const double A[3][3], double B[3][3], double m, long e)
			{
				int i, j;
				
				/* initialize: B = A */
				if (A != B) {
					for (i = 0; i < 3; ++i)
						for (j = 0; j < 3; ++j)
							B[i][j] = A[i][j];
				}
				/* Compute B = A^(2^e) mod m */
				for (i = 0; i < e; i++)
					MatMatModM (B, B, B, m);
			}

			/**
			* Compute the vector v = A*s MOD m. Assume that -m < s[i] < m.
			* Works also when v = s.
			*  \author Pierre L'Ecuyer
			*/
			__device__
			void MatVecModM (double A[3][3], double s[3], double v[3],
								double m)
			{
				int i;
				double x[3];               // Necessary if v = s
				
				for (i = 0; i < 3; ++i) {
					x[i] = MultModM (A[i][0], s[0], 0.0, m);
					x[i] = MultModM (A[i][1], s[1], x[i], m);
					x[i] = MultModM (A[i][2], s[2], x[i], m);
				}
				for (i = 0; i < 3; ++i)
					v[i] = x[i];
			}
			
		}; // end of struct Math
		} // end of namespace mrg32k3a
	} // end of namepace util
} // end of namespace shoverand


#endif // UTIL_H
