#include <cstddef>
#include <iostream>

template<class T>
T* merge2(const T* a, size_t sa, const T* b, size_t sb, T* c)
{
  size_t i = 0, j = 0, k = 0;
  while (i < sa && j < sb)
  {
    if (a[i] <= b[j])
    {
      c[k++] = a[i++];
    }
    else
    {
      c[k++] = b[j++];
    }
  }
  while (i < sa)
  {
    c[k++] = a[i++];
  }

  while (j < sb)
  {
    c[k++] = b[j++];
  }
  return c;
}

template< class T >
T* merge(const T* const* a, size_t sa, const size_t* sai, T* c)
{
  for (size_t i = 0; i < sai[0]; ++i)
  {
    c[i] = a[0][i];
  }

  size_t i = 1, k = sai[0];
  while (i < sa)
  {
    T* tmp = new T[k + sai[i]];
    try
    {
      merge2(a[i], sai[i], c, k, tmp);
      for(size_t j = 0; j < k + sai[i]; ++j)
      {
        c[j] = tmp[j];
      }
      k += sai[i];
      delete[] tmp;
    }
    catch (...)
    {
      delete[] tmp;
      throw;
    }
    i++;
  }
  return c;
}
