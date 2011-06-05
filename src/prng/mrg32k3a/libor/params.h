
// parameters for LIBOR calculation

#define NN 80
#define NMAT 40
#define L2_SIZE 3280 //NN*(NMAT+1)
#define NOPT 15
#define NPATH 96000

// NOTE: L2 local array gets held in frame buffer
// and requires 4*L2_SIZE*max_threads bytes where
// max_threads is maximum number of active threads
