/*
** main.c for my_ftl in /home/flay/works/my_ftl
**
** Made by SCHRIEVER Flavien
** Login <schrie_f@etna-alternance.net>
**
** Started on  Nov 06 10:18 AM 2017 SCHRIEVER Flavien
** Last update Nov 06 10:18 AM 2017 SCHRIEVER Flavien
*/
#include "engine2d.h"

int					main(int argc, char **argv)
{
    t_engine		engine;
	time_t			now;

	if ((now = time(NULL)) == ((time_t) -1))
		return (1);
	srandom (time (NULL));
    if ((engine.ship = create_ship()) == NULL)
		return (1);
	if ((engine.game = create_game(engine.ship)) != NULL)
	{
		if (argc > 1 && my_strcmp(argv[1], "--gui") == 0)
			sdl_game(&engine);
		else
			classic_game(&engine);
	}
    print_result(engine.ship);
	free_ship(engine.ship);
	free_game(engine.game);
	return (0);
}
