/***********************************************************************\
 *
 * File:           RngStream.h for multiple streams of Random Numbers
 * Language:       C++ (ISO 1998)
 * Copyright:      Pierre L'Ecuyer, University of Montreal
 * Notice:         This code can be used freely for personal, academic,
 *                 or non-commercial purposes. For commercial purposes, 
 *                 please contact P. L'Ecuyer at: lecuyer@iro.umontreal.ca
 * Date:           14 August 2001
 *
 * Modified by jH@CKtheRipper, 03/22/11 [added MySubstream class, removed anonymous namespace]
 \***********************************************************************/


 
#ifndef RNGSTREAM_H
#define RNGSTREAM_H
 
#include <string>

class RngStream
{
public:

RngStream (const char *name = "");


static bool SetPackageSeed (const unsigned long seed[6]);


void ResetStartStream ();


void ResetStartSubstream ();


void ResetNextSubstream ();


void SetAntithetic (bool a);


void IncreasedPrecis (bool incp);


bool SetSeed (const unsigned long seed[6]);


void AdvanceState (long e, long c);


void GetState (unsigned long seed[6]) const;


void WriteState () const;


void WriteStateFull () const;


double RandU01 ();


int RandInt (int i, int j);



public:

double Cg[6], Bg[6], Ig[6];


bool anti, incPrec;


std::string name;


static double nextSeed[6];


double U01 ();


double U01d ();


};
 

class MySubstream {
private:
   /** Current SubStream state */
   double Cg_[6]; 
   
   /** Starting state of the current substream */
   double Bg_[6];
   
public:
   /** Init through RngStream */
   MySubstream(const RngStream&);
   
   /** Draw next number */
   double next();
   
   /** Jump n substreams ahead in current stream */
   void jumpAhead(long n);
   
};

#endif
 

