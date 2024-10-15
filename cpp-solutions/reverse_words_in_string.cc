#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using std::cout; using std::endl;

std::string reverseWords(std::string input_str)
{
  std::string output_str = input_str;
  size_t left = 0, right = 0;
  // идём по строке, двигая указатель right.
  // натыкаясь на пробел. мы заводим временный указатель, который бежит
  // в обратную сторону от rihgt-1 до left во внутреннем цикле.
  // То есть мы проходимся по слову второй раз, только задом наперёд.
  // left при этом инкрементируется. Он указывает на позицию в выходной строке
  // натолкнувшись на конец строки мы реагируем также как на пробел.
  // заканчиваем работу цикла когда указателем left пройдём всю строку.
  // размер исходной строки равен размеру выходной.
  // right - для исходной строки. left - для выходной строки
  // Как итог мы проходим каждое слово дважды, что даёт сложность
  // O(2*n) = O(n)
  while (left < input_str.size()) {
    // если input_str[right] == ' ',
    // то переходи к else
    // если right == input_str.size(),
    // то переходи к else
    //if ((right != input_str.size() && input_str[rihgt] != ' '))

    size_t word_len;
    if (right != input_str.size() && input_str[right] != ' ') {
      right++; 
    }
    else {
      word_len = right-left;
      for (size_t i=1; i<=word_len; i++) {
        output_str[left] = input_str[right-i];
        left++;
      }
      // increment after space
      left++; right++;
      assert(left == right);
    }
  }

  return output_str;
}

std::string reverseWords_sol(std::string input_str)
{
  size_t left = 0, right = 0;
  for (right=0; left<input_str.length(); right++) {
    if (right == input_str.length() || input_str[right] == ' ') {
      std::reverse(input_str.begin() + left, input_str.begin() + right);
      left = right;
      left++;
    }
  }
  return input_str;
}


int main(void)
{
  std::string my_str{"My name is Marshall"};
  //cout << reverseWords(my_str) << endl;
  cout << my_str << endl;
  cout << reverseWords_sol(my_str) << endl;
  return 0;
}
