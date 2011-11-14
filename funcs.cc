#include <stdio.h>
#include <iostream>
#include <unistd.h> //for the getopt function
#include <stdlib.h> //for atoi

bool parseParams(int argc, char *argv[ ], int& cache_capacity,
				int& cache_blocksize, int& cache_associativity)
{
  //needed for the parsing of command line options
  int c;
  bool c_flag, b_flag, a_flag;
  bool errflg = false;

  c_flag = b_flag = a_flag = errflg = false;

  //the following variables are used by getopt and
  //are defined elsewhere so we just make them
  //extern here
  extern char *optarg;
  extern int optind, optopt;

  //start the parsing of the command line options.
  //end is indicated by getopt returning -1
  //each option has a case statement
  //the corresponding flags are set if the option exists on
  //the command line
  //the : int he getopt indicates that the option preceeding the
  //: requires a argument to be specified
  while ((c = getopt(argc, argv, "c:b:a:")) != -1) {
	switch (c) {
	  case 'c':
		  cache_capacity = atoi(optarg);
		  if (
		    cache_capacity == 4 ||
		    cache_capacity == 8 ||
		    cache_capacity == 16 ||
		    cache_capacity == 32 ||
		    cache_capacity == 64) {
			  c_flag = true;
		  }
		  else {
		    c_flag = false;
		  }
		  break;
	  case 'b':
		  cache_blocksize = atoi(optarg);
		  if (
		    cache_blocksize == 4 ||
		    cache_blocksize == 8 ||
		    cache_blocksize == 16 ||
		    cache_blocksize == 32 ||
		    cache_blocksize == 64 ||
		    cache_blocksize == 128 ||
		    cache_blocksize == 256 ||
		    cache_blocksize == 512) 
		  {
		    b_flag = true;
		  }
		  else {
		    b_flag = false;
		  }
		  break;
	  case 'a':
		  cache_associativity = atoi(optarg);
		  if (
		    cache_associativity == 1 ||
		    cache_associativity == 2 ||
		    cache_associativity == 4 ||
		    cache_associativity == 8 ||
		    cache_associativity == 16)
		  {
		    a_flag = true;
		  }
		  else {
		    a_flag = false;
		  }
		  break;
	  case ':':       /* -c without operand */
		  fprintf(stderr,
		  	"Option -%c requires an operand\n", optopt);
		  errflg++;
		  break;
	  case '?':
		  fprintf(stderr, "Unrecognised option: -%c\n", optopt);
		  errflg=true;
	  }
  }

  //check if we have all the options and have no illegal options
  if(errflg || !c_flag || !b_flag || !a_flag) {
	  fprintf(stderr, "usage: %s -c<capacity> -b<blocksize> -a<associativity>\n", argv[0]);
	  return false;
  }

  return true;

}

