#include "philosophers.h"

void	*do_this(void *pointer)
{
	int i;

	i = 0;
	while (i < 100)
	{
		i++;
	}
	return (pointer);
}

int main()
{
	pthread_t one;
	pthread_t two[5];
	
	char*	observer;
	int			num_philos;
	int			i;

	observer = NULL;
	if (pthread_create(&one, NULL, do_this, &observer) != 0)
		return (3);
	i = 0;
	while (i < num_philos)
	{
		if (pthread_create(&two[i], NULL, do_this,
				&observer) != 0)
			return (3);
		i++;
	}
	//if (pthread_join(observer, NULL) != 0)
		//return (safe_exit("Thread join error", program, forks, 3));
	i = 0;
	//printf("asdasdasd\n");
	while (i < num_philos)
	{
		if (pthread_join(two[i], NULL) != 0)
			return (4);
		i++;
	}
	if (pthread_join(one, NULL) != 0)
		return (4);
	/* pthread_mutex_lock(program->philos->write_lock);
	printf("asdasdasasdasdasdd\n");
	pthread_mutex_unlock(program->philos->write_lock); */
	printf("here\n");
	return (1);
}