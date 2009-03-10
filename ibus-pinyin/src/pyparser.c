#include <glib.h>
#include "lex.yy.h"
#include "pinyin.h"

int main(int argc, char **argv)
{
	YY_BUFFER_STATE b;
	yyscan_t scanner;
	GList *list;

	if (argc <= 2)
		return 0;

	gchar *buf = g_strdup (argv[2]);	
	g_strreverse (buf);

	yylex_init_extra (atoi(argv[1]), &scanner);
	b = yy_scan_string (buf, scanner);
	
	if (yyparse (&list, scanner) == 0) {
		GList *p;
		for (p = list; p != NULL; p = p->next) {
			printf ("%s ", ((struct pinyin_t *)p->data)->py);
		}
		printf("\n");
		for (p = list; p != NULL; p = p->next) {
			printf ("%s ", ((struct pinyin_t *)p->data)->origin_py);
			g_slice_free (struct pinyin_t, p->data);
		}
		printf("\n");

		g_list_free (list);
	}
	yy_delete_buffer (b, scanner);
	yylex_destroy (scanner);
}
