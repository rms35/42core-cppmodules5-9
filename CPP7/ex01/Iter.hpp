
#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void	iter(T* arr, const unsigned int length, F ft)
{
	for (unsigned int i = 0; i < length; i++)
		ft(arr[i]);
}

#endif //ITER_HPP
