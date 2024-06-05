#ifndef ENV_H
#define ENV_H

//state_output
//state_error_output

void game_menu_output();

void single_mode_output();
void single_mode_easy_output();
void single_mode_hard_output();

void multi_mode_output();
void multi_mode_original_output();
void multi_mode_speed_output_first();
void multi_mode_speed_output_second();


void input_domain_error_output();
void wrong_position_error_output();

void board_output();
void place_marker(char ch, int row, int col);

void time_over_output();
void win_computer_output();
void game_draw_output();
void win_player_output();
void win_player_1_output();
void win_player_2_output();

#endif
