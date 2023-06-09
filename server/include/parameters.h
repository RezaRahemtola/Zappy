/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** parameters
*/

#pragma once

#define PARAMS_DEFAULT_PORT 4242
#define PARAMS_DEFAULT_WIDTH 10
#define PARAMS_DEFAULT_HEIGHT 10
#define PARAMS_DEFAULT_CLIENTS 3
#define PARAMS_DEFAULT_FREQ 100

#define GUI_TEAM_NAME "GRAPHIC"

#include <stdbool.h>
#include <stddef.h>
#include "types.h"

// Utils
params_t *get_params(int argc, char *const *argv);
void destroy_params(params_t *params);

// Setters
void set_nb_param(size_t *storage, bool *error);
void set_teams(char *const *argv, params_t *params, bool *error);
void set_teams_clients_nb(params_t *params);

// Checks
void check_params(params_t *params, bool *error);

// Destroy
void destroy_team(team_t *team);
