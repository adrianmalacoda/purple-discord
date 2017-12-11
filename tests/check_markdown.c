#include <check.h>
//#include "../glib_compat.h"

//static gchar * discord_escape_md(const gchar *markdown);
#include "../libdiscord.c"

START_TEST(test_escape_md)
{
    printf("%s\n", discord_escape_md("__"));
    printf("%s\n", discord_escape_md("__foo"));
    printf("%s\n", discord_escape_md("__foo__"));
    printf("%s\n", discord_escape_md("__foo__ bar"));
    printf("%s\n", discord_escape_md("__foo__ __bar_"));
    printf("%s\n", discord_escape_md("__foo__ __bar__"));
    printf("%s\n", discord_escape_md("__foo__ __bar__ **baz"));
}
END_TEST
 
Suite * markdown_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Markdown");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_escape_md);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = markdown_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}
