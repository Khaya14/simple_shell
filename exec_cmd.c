lude <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 *  *  * exec_cmd - executes the users input
 *   *   * @cmd: the character string to be executed
 *    *    *
 *     *     * Return: 0 on success, else -1.
 *      *      */
int exec_cmd(char *cmd)
{
	        char **tkn_arr = malloc(sizeof(char *) * 1024);
		        char *tkn;
			        pid_t kind_pid;
				        int cnt, status;

					        if (tkn_arr == NULL)
							                return (-1);

						        tkn = strtok(cmd, " \n");
							        for (cnt = 0; tkn != NULL; cnt++)
									        {
											                tkn_arr[cnt] = tkn;
													                tkn = strtok(NULL, " \n");
															        }

								        tkn_arr[cnt] = NULL;

									        if (cnt > 0)
											        {
													                if (strcmp(tkn_arr[0], "exit") == 0)
																                        exit(EXIT_SUCCESS);
															                else if (strcmp(tkn_arr[0], "env") == 0)
																		                {
																								char **env_ptr = NULL;
																								for (env_ptr = environ;  *env_ptr != NULL; env_ptr++)
																								{
																									printf("%s\n", *env_ptr);
																								}
																				}
															else
															{
																kind_pid = fork();\
																	   if (kind_pid == -1)
																	   {
																		   perror("fork");
																		   return (-1);
																	   }
																	   else if (kind_pid == 0)
																	   }
															if (execve(tkn_arr[0], tkn_arr, environ) == -1)
															{
															perror(tkn_arr[0]);
															return (-1);
															}
												}
										else                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         {
																								wait(status);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }
																								                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }
																								                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         }
																								                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 free(tkn_arr);
																								                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 return (0);
																								                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }
	free(tkn_arr);
	return (0);
}
