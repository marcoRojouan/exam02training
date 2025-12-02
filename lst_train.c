#include "list.h"
#include <unistd.h>

int	ft_lst_size(t_list *lst)
{
	int i = 0;

	if (!lst)
		return (0);
	while(lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int tmp;
	t_list *begin_ptr;

	if (!lst)
		return (NULL);
	begin_ptr = lst;
	while (lst && lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{	
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = begin_ptr;
		}
		else 
			lst = lst->next;
	}
	return (begin_ptr);
}

void ft_lst_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return ;
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*current;

	if (!*begin_list || !begin_list)
		return ; 
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0x0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	current = *begin_list;
	while (current && current->next)
	{
		if(cmp(current->next->data, data_ref) == 0)
		{	
			tmp = current->next;
			current->next = tmp->next;
			free(tmp);
		}
		else
		current = current->next;
	}
}

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = malloc(sizeof(struct s_list));
// 	if (!new)
// 		return (NULL);
// 	new->data = content;
// 	new->next = NULL;
// 	return (new);
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list	*last;

// 	if (!lst)
// 		return (NULL);
// 	last = lst;
// 	while (last->next)
// 		last = last->next;
// 	return (last);
// }

// void	ft_lst_push_back(t_list **begin_list, void *data)
// {
// 	t_list *last;
// 	t_list *new;
	
// 	new = ft_lstnew(data);
// 	if(!*begin_list)
// 	{
// 		*begin_list = new;
// 		return ;
// 	}
// 	last = ft_lstlast(*begin_list);
// 	last->next = new;
// }

// t_list *ft_lst_find(t_list *begin_list, void *data_ref, int (*cmp)())
// {
// 	t_list *element;

// 	if (!begin_list)
// 		return (NULL); 
// 	while (begin_list)
// 	{
// 		if (cmp(begin_list->data, data_ref) == 0)
// 		{
// 			element = begin_list;
// 			return (element);
// 		}
// 		begin_list = begin_list->next;
// 	}
// 	return (NULL);
// }