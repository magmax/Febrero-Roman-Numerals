#include <string.h>
#include <stdlib.h>
#include "maintest.h"
#include "roman.h"


#ifndef NULL
# define NULL 0
#endif


static int check (int arabian, char* expected)
{
  char* roman;
  int result;

  roman = to_roman(arabian);

  result = strcmp (expected, roman);

  free_roman (roman);
  return result;

}

static int test_one(parameters_t* parameters)
{
  return check (1, "I");
}

static int test_two(parameters_t* parameters)
{
  return check (2, "II");
}


/* Funciones genéricas para las pruebas */

static void setTest ( test_s* test, PF_Test function, char* description)
{
  int i;
  test->function = function;
  strncpy (test->description, description, 49);
  test->description[50] = ' ';
  for (i = 49; !test->description[i] && i; --i)
    test->description[i] = '.';
}


test_s* getTests ()
{
  test_s* tests;
  int test_number = 2; // EDIT
  tests = calloc ( test_number+1, sizeof( test_s ) );

  // fill tests here:
  setTest ( &tests[0], test_one, "1");
  setTest ( &tests[1], test_two, "2");
  // test end.

  setTest ( &tests[test_number], NULL, "");

  return tests;
}

void     freeTests(test_s* tests)
{
  free (tests);
}

parameters_t*    setUp()
{
  return NULL;
}

void     tearDown(parameters_t* parameters)
{
  // do nothing
}
