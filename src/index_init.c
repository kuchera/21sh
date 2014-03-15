#include "index.h"

#include "fun_cat.h"
#include "fun_cd.h"
#include "fun_echo.h"
#include "fun_exit.h"
#include "fun_help.h"
#include "fun_ls.h"
#include "fun_man.h"
#include "fun_pwd.h"
#include "fun_time.h"

void i_init()
{
	i_add("cat", &fun_cat);
	i_add("cd", &fun_cd);
	i_add("echo", &fun_echo);
	i_add("exit", &fun_exit);
	i_add("help", &fun_help);
	i_add("ls", &fun_ls);
	i_add("man", &fun_man);
	i_add("pwd", &fun_pwd);
	i_add("time", &fun_time);
}
