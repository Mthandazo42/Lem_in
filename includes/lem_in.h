/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:31:19 by tmaze             #+#    #+#             */
/*   Updated: 2019/05/09 17:39:33 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "limits.h"

typedef struct		s_node
{
	char			*name;
	int				x;
	int				y;
	char			role;
	int				ind;
	struct s_node	*next;
}					t_node;

typedef struct		s_ind
{
	int				index;
	int				weight;
	struct s_ind	*next;
}					t_ind;

typedef struct		s_bfs
{
	int				parent;
	char			visited;
	char			old_visited;
	int				queue;
}					t_bfs;

typedef struct		s_ants
{
	int				nb_ant;
	int				nb_path;
	int				nb_node;
	char			end;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_temp
{
	int				src_ind;
	int				dest_ind;
	struct s_temp	*next;
}					t_temp;

typedef struct		s_holder
{
	int				count;
	int				nb_state;
	int				s_cmd;
	int				s_pos;
	int				error;
	int				s_error;
	int				state;
	int				e_error;
	int				v_error;
	int				l_error;
	int				gr_status;
	int				s_vert;
	int				e_vert;
	int				e_cmd;
	int				e_pos;
	int				v_flag;
	t_temp			*data;
}					t_holder;

typedef struct		s_rdata
{
	char			*line;
	struct s_rdata	*next;
}					t_rdata;

typedef	struct		s_lmdata
{
	int				nbants;
	int				nb_nodes;
	int				nb_paths_max;
	t_node			*nodes_data;
	t_ind			**adj;
	t_rdata			*map;
}					t_lmdata;

int					lm_parser(t_lmdata *ldata
							, t_holder *holder);
int					lm_check_room_before(char **tab, t_holder *holder
							, char **name);
void				lm_clear_unv(t_holder *holder);
int					lm_add_vertex(t_lmdata *ldata, char *raw, char flag
							, t_holder *holder);
int					lm_ext_conn(t_holder *holder, t_lmdata *data
							, char *raw);
void				lm_ext_conn_sub(t_holder *holder, t_temp *new_data);
int					lm_init_src_dest(int *src, int *dest, t_lmdata *data
							, char *raw);
int					lm_find_index(t_lmdata *data, char *str);
void				lm_get_cmd_vertices(int count, t_holder *holder
							, t_lmdata *ldata, char *line);
int					lm_get_value(char *line);
void				lm_check_start_vert(int count, t_holder *hol
							, t_lmdata *ldata, char *line);
void				lm_check_end_vert(int count, t_holder *hol
							, t_lmdata *ldata, char *line);
void				lm_get_vert_link(int count, t_lmdata *ldata
							, t_holder *holder, char *line);
int					lm_validate_rooms(char *name, char *x, char *y);
int					lm_adj_parser(t_lmdata *lmdata, t_holder *holder);
void				lm_init_data(t_holder *holder, t_lmdata *ldata);
int					lm_verify_cmd(t_holder *holder, t_lmdata *data);
void				lm_initdata(t_lmdata *data);
int					lm_error_nbr(char *raw);
int					lm_getparams(t_lmdata *data);
void				lm_clean_data(t_lmdata *data);
int					lm_check_forbiden_chars(char *line, int flag);
t_ind				**lst_indinit(t_lmdata *data);
int					lst_indadd_link(t_lmdata *data, int n1, int n2);
t_ind				*lst_indadd(t_ind **lst, int ind);
void				lst_inddel(t_ind **lst);
void				tablst_inddel(t_ind **tab);

t_ants				*add_ant(t_ants	**ants, int nb_ant, int nb_path
							, t_ind **paths);
void				del_ants(t_ants **ants);
t_node				*get_node(t_lmdata *data, int index);
t_ind				*get_node_path(t_ind *lst, int index);

void				bfs(t_lmdata *data, t_bfs *tab, int start_ind
							, int end_ind);
t_ind				**edmonds_karp(t_lmdata *data, int s_ind, int e_ind);
int					get_score(t_lmdata *data, t_ind **ret, int nb_paths);
void				print_paths(t_lmdata *data, t_ind **ret);
int					push_ants(t_lmdata *data, t_ind **paths
							, int nb_paths);
void				push_ants_end(t_lmdata *data, char *e_name);

void				del_map(t_lmdata *data);
int					add_line_map(t_lmdata *data, char *line);
void				print_map(t_lmdata *data);

t_node				*get_node_role(t_lmdata *data, char role);
int					get_nb_paths(t_ind **ret);
void				get_nb_paths_max(t_lmdata *data, int start, int end);

#endif
