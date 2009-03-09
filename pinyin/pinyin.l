%{
#include <stdio.h>
#include <glib.h>
#include "y.tab.h"

static gchar *py_dup (const gchar *str)
{
	gchar *new_str;

	new_str = g_slice_alloc (8);
	strcpy (new_str, str);
	return new_str;
}
%}

%%

a|ia|na|gna|oa|ab|iab|nab|gnab|oab|ieb|neb|gneb|ib|naib|oaib|eib|nib|gnib|ob|ub|ac|iac|nac|gnac|oac|ec|nec|gnec|ahc|iahc|nahc|gnahc|oahc|ehc|nehc|gnehc|ihc|gnohc|uohc|uhc|iauhc|nauhc|gnauhc|iuhc|nuhc|ouhc|ic|gnoc|uoc|uc|nauc|iuc|nuc|ouc|ad|iad|nad|gnad|oad|ed|ied|gned|id|aid|naid|oaid|eid|gnid|uid|gnod|uod|ud|naud|iud|nud|oud|e|ie|ne|re|af|naf|gnaf|ief|nef|gnef|of|uof|uf|ag|iag|nag|gnag|oag|eg|ieg|neg|gneg|gnog|uog|ug|aug|iaug|naug|gnaug|iug|nug|oug|ah|iah|nah|gnah|oah|eh|ieh|neh|gneh|gnoh|uoh|uh|auh|iauh|nauh|gnauh|iuh|nuh|ouh|ij|aij|naij|gnaij|oaij|eij|nij|gnij|gnoij|uij|uj|nauj|euj|nuj|ak|iak|nak|gnak|oak|ek|nek|gnek|gnok|uok|uk|auk|iauk|nauk|gnauk|iuk|nuk|ouk|al|ial|nal|gnal|oal|el|iel|gnel|il|ail|nail|gnail|oail|eil|nil|gnil|uil|ol|gnol|uol|ul|naul|eul|nul|oul|vl|am|iam|nam|gnam|oam|em|iem|nem|gnem|im|naim|oaim|eim|nim|gnim|uim|om|uom|um|an|ian|nan|gnan|oan|en|ien|nen|gnen|gn|in|nain|gnain|oain|ein|nin|gnin|uin|gnon|uon|un|naun|eun|oun|vn|o|uo|ap|iap|nap|gnap|oap|iep|nep|gnep|ip|naip|oaip|eip|nip|gnip|op|uop|up|iq|aiq|naiq|gnaiq|oaiq|eiq|niq|gniq|gnoiq|uiq|uq|nauq|euq|nuq|nar|gnar|oar|er|ner|gner|ir|gnor|uor|ur|naur|iur|nur|our|as|ias|nas|gnas|oas|es|nes|gnes|ahs|iahs|nahs|gnahs|oahs|ehs|iehs|nehs|gnehs|ihs|uohs|uhs|auhs|iauhs|nauhs|gnauhs|iuhs|nuhs|ouhs|is|gnos|uos|us|naus|ius|nus|ous|at|iat|nat|gnat|oat|et|gnet|it|nait|oait|eit|gnit|gnot|uot|ut|naut|iut|nut|out|aw|iaw|naw|gnaw|iew|new|gnew|ow|uw|ix|aix|naix|gnaix|oaix|eix|nix|gnix|gnoix|uix|ux|naux|eux|nux|ay|nay|gnay|oay|ey|iy|niy|gniy|oy|gnoy|uoy|uy|nauy|euy|nuy|az|iaz|naz|gnaz|oaz|ez|iez|nez|gnez|ahz|iahz|nahz|gnahz|oahz|ehz|nehz|gnehz|ihz|gnohz|uohz|uhz|auhz|iauhz|nauhz|gnauhz|iuhz|nuhz|ouhz|iz|gnoz|uoz|uz|nauz|iuz|nuz|ouz { yylval.str = py_dup (yytext); return PINYIN;}

b|c|hc|d|f|g|h|j|k|l|m|n|p|q|r|s|hs|t|w|x|y|z|hz { yylval.str = py_dup (yytext); return SHENGMU;}
' {return '\'';}

.  

%%
