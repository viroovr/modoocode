#include <iostream>

class Array {
  const int dim; //몇차원 배열인지 알려준다.
  int* size; // size[0] * size[1] * ... * size[dim-1] 짜리 배열이다.
  
  struct Address 
  {
    /*
      맨 마지막 레벨 (dim-1 레벨)은 데이터 배열을 가리키고, 그 위 상위
      레벨 에서는 다음 Address 배열을 가리킨다.
    */
    int level;

    void* next;
  };
  

  Address* top;

  public:
    Array(int dim, int* array_size) :dim(dim) {
      size = new int[dim];
      for(int i = 0; i < dim; i++) size[i] = array_size[i];
    }

    void initialize_address(Address *current){
      if (!current) return;
      if(current->level == dim-1) {
        current->next = new int[size[current->level]];
        return;
      }
      current->next = new Address[size[current->level]];
      for (int i = 0; i != size[current->level]; i++)
      {
        (static_cast<Address *> (current->next) + i) ->level = current->level + 1;
        initialize_address(static_cast<Address *>(current->next) + i);
      }
      
    }
    void delete_address(Address *current){
      if(!current) return;
      for (int i = 0; current->level < dim-1 && i < size[current->level]; i++)
      {
        delete_address(static_cast<Address *>(current->next) + i);
      }
      
      if(current->level == dim -1){
        delete[] static_cast<int *>(current->next);
      }

      delete[] static_cast<Address *>(current->next);
    }
};