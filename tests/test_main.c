#include <CUnit/Basic.h>
#include "test_common.h"


int main(int argc, char** argv) {

        CU_pSuite p_suite = NULL;

        if (CUE_SUCCESS != CU_initialize_registry())
                return CU_get_error();

        p_suite = CU_add_suite("VECTOR TESTS", NULL, NULL);
        if (p_suite == NULL) {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if (CU_add_test(p_suite, "test_ctor", test_vector_ctor) == NULL ||
            CU_add_test(p_suite, "test_ctor_list", test_vector_ctor_list) == NULL ||
            CU_add_test(p_suite, "test_reserve", test_vector_reserve) == NULL ||
            CU_add_test(p_suite, "test_data", test_vector_data) == NULL ||
            CU_add_test(p_suite, "test_get", test_vector_get) == NULL ||
            CU_add_test(p_suite, "vector_at", test_vector_at) == NULL ||
            CU_add_test(p_suite, "vector_front", test_vector_front) == NULL ||
            CU_add_test(p_suite, "vector_back", test_vector_back) == NULL ||
            CU_add_test(p_suite, "vector_insert", test_vector_insert) == NULL ||
            CU_add_test(p_suite, "vector_erase", test_vector_erase) == NULL ||
            CU_add_test(p_suite, "vector_clear", test_vector_clear) == NULL) {
                CU_cleanup_registry();
                return CU_get_error();
        }

        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}
