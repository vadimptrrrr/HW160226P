#include <cstddef>

template< class T >
T* merge(const T* const* a, size_t sa, const size_t* sai, T* c)
{
  size_t i = 0, j = 0, k = 0;
  while (i < sa)
  {
    while (j < sai[i])
    {
      c[k] = a[i][j];           //T::operator=
      k++;
      j++;
    }
    i++;
    j = 0;
  }
  return c;
}