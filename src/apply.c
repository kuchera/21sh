#include "apply.h"

int apply(my_tab t)
{
	my_tab tt = NULL;
	my_tab tc = r_cp(t);;
	int i = 0;
	while (my_tlen(tc) > 0)
	{
		tt = r_first(tc, ";");
		if (is_redirect(t))
			i = redirect(tt);
		else
			i = i_call(tt);
		my_tfree(tt);
		if (i != 0)
			break;
	}
	my_tfree(tc);
	return i;
}

my_tab r_cp(my_tab t)
{
        my_tab tt = my_tnew();
        int i;
        for (i=0 ; i< my_tlen(t) ; ++i)
                my_tadd(tt, my_tget(t, i));
        return tt;
}

my_tab r_first(my_tab t, const char *sep)
{
        my_tab tt = my_tnew();
        char *s;
        while (my_tlen(t) > 0)
        {
                s = my_trmat(t, 0);
                if (!strcmp(sep, s))
                        return tt;
                my_tadd(tt, s);
        }
        return tt;
}

