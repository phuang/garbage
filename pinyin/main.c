#include <glib.h>
#include "lex.yy.h"

int main(int argc, char **argv)
{
	YY_BUFFER_STATE b;
	yyscan_t scanner;

	GList *list;

	gchar *buf = g_strdup (argv[1]);	
	g_strreverse (buf);

	yylex_init_extra (0xffff, &scanner);
	b = yy_scan_string (buf, scanner);
	
	if (yyparse (&list, scanner) == 0) {
		GList *p;
		for (p = list; p != NULL; p = p->next) {
			printf ("%s ", p->data);
			g_slice_free1 (8, p->data);
		}
		printf("\n");
		g_list_free (list);
	}
	yy_delete_buffer (b, scanner);
	yylex_destroy (scanner);
}
