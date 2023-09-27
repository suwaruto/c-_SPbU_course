#pragma once

#include <vector>

//v1 and v2 are assumed sorted everywhere

template <typename T>
std::vector<T> intersect( const std::vector<T>& v1, const std::vector<T>& v2 )
{
  std::vector<T> res;
  for (auto it_v1 = v1.begin(), it_v2 = v2.begin();
      it_v1 != v1.end() && it_v2 != v2.end();
      )
  {
    if (*it_v1 < *it_v2)
      it_v1++;
    else if (*it_v1 > *it_v2)
      it_v2++;
    else
    {
      res.push_back(*it_v1++);
      it_v2++;
    }
  }
  return res;
}

template <typename T>
std::vector<T> unite( const std::vector<T>& v1, const std::vector<T>& v2 )
{
  std::vector<T> res;
  for (auto it_v1 = v1.begin(), it_v2 = v2.begin();
      it_v1 != v1.end() || it_v2 != v2.end();
      )
  {
    if (it_v1 != v1.end() && (it_v2 == v2.end() || *it_v1 < *it_v2))
    {
      res.push_back(*it_v1++);  
    }
    else if (it_v1 == v1.end() || *it_v2 < *it_v1)
    {
      res.push_back(*it_v2++);
    }
    else if (*it_v1 == *it_v2)
    {
      res.push_back(*it_v1++);
      it_v2++;
    }
  }
  return res;
}

template <typename T>
std::vector<T> substract( const std::vector<T>& v1, const std::vector<T>& v2 )
{
  std::vector<T> res;
  for (auto it_v1 = v1.begin(), it_v2 = v2.begin();
      it_v1 != v1.end() && it_v2 != v2.end();
      )
  {
    if (*it_v1 < *it_v2)
      res.push_back(*it_v1++);
    else if (*it_v1 == *it_v2)
    {
      it_v1++;
      it_v2++;
    }
    else
      it_v2++;
  }
  return res;
}
