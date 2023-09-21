#include "shell.h"

/**
 * env - prints the current environment
 * @myinfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int env(info_t *myinfo)
{
	print_ls_str(myinfo->env);
	return (0);
}

/**
 * get_env - gets the value of an environ variable
 * @myinfo: Structure containing potential arguments. Used to maintain
 * @myname: env var name
 *
 * Return: the value
 */
char *get_env(info_t *myinfo, const char *myname)
{
	list_t *node1 = myinfo->env;
	char *myp;

	while (node1)
	{
		myp = mystarts_with(node1->str, myname);
		if (myp && *myp)
			return (myp);
		node1 = node1->next;
	}
	return (NULL);
}

/**
 * set_env - Initialize a new environment variable,
 *             or modify an existing one
 * @myinfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int set_env(info_t *myinfo)
{
	if (myinfo->argc != 3)
	{
		rputs("Incorrect number of arguements\n");
		return (1);
	}
	if (setenv(myinfo, myinfo->argv[1], myinfo->argv[2]))
		return (0);
	return (1);
}

/** 
* remove_setenv - Remove an environment variable 
* @myinfo: Structure containing potential arguments. Used to maintain constant function prototype.
* Return: Alwyas 0
*/
int remove_setenv(info_t *myinfo)
{
	int i;

	if (myinfo->argc == 1)
	{
		rputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= myinfo->argc; i++)
		_setenv(myinfo, myinfo->argv[i]);

	return (0);
}
/**
 * populate1_env_ls1 - populates env linked list
 * @myinfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate1_env_ls1(info_t *myinfo)
{
	list_t *node1 = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		myadd_node1_end(&node1, environ[i], 0);
	myinfo->env = node1;
	return (0);
}
