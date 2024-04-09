# 👾42_So_long 👾
This project is about creating a 2D game with minilibx
***

**✅Objective✅**

In this project we will be creating a 2D game using functions from a library created by 42 students called "minilibx" in C language.

To achieve that we will be using images in .xpm format. So that way we can put them into the window. Once we print the map we will be controlling every single move to make sure the score is updated correctely and the end of the game is available.

**📝Functions📝**

`void	init_map(t_window *wd);` : This is the main function that will initializate all the map and the window.

`int    game_update(t_window *wd);` : This is the main function that controls every movement and update the window where the game will print every movement or sprite.

`int	key_event(int key, t_window *param);` : This function called in the mlx loop functions is used to manage every single key pressed on the keyboard.

`void	end_game(t_window **wd);` : This function controls when the game ends and call the respective functions to free the map and the window.
