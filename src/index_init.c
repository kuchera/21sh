#include "index.h"

#include "fun_cat.h"
#include "fun_echo.h"
#include "fun_exit.h"
#include "fun_help.h"
#include "fun_man.h"

void i_init()
{
	i_add("cat", &fun_cat);
	i_add("echo", &fun_echo);
	i_add("exit", &fun_exit);
	i_add("help", &fun_help);
	i_add("man", &fun_man);
}
