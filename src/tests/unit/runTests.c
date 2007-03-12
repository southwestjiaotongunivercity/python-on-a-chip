#include "CuTest.h"


/* Need to declare this array since no PyMite application is linked */
const unsigned char usr_nat_fxn_table[] = {};

CuSuite *getSuite_testHeap(void);
CuSuite *getSuite_testDict(void);
CuSuite *getSuite_testList(void);
CuSuite *getSuite_testSeglist(void);
CuSuite *getSuite_testCodeObj(void);
CuSuite *getSuite_testFuncObj(void);
CuSuite *getSuite_testIntObj(void);
CuSuite *getSuite_testInterp(void);
CuSuite *getSuite_testStringObj(void);
CuSuite *getSuite_testTupleObj(void);


int main(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, getSuite_testHeap());
    CuSuiteAddSuite(suite, getSuite_testSeglist());
    CuSuiteAddSuite(suite, getSuite_testDict());
    CuSuiteAddSuite(suite, getSuite_testList());
    CuSuiteAddSuite(suite, getSuite_testCodeObj());
    CuSuiteAddSuite(suite, getSuite_testFuncObj());
    CuSuiteAddSuite(suite, getSuite_testIntObj());
    CuSuiteAddSuite(suite, getSuite_testInterp());
    CuSuiteAddSuite(suite, getSuite_testStringObj());
    CuSuiteAddSuite(suite, getSuite_testTupleObj());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    puts(output->buffer);

    /*
     * Zero failures indicates an all-good exit code.
     * Any errors gives a non-zero exit code that should stop the build
     * when this is called by the Makefile
     */
    return suite->failCount;
}
