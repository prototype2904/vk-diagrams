#ifndef ER_DIAGRAM_H
#define ER_DIAGRAM_H
#include <string>
#include <vector>
template <typename T>
class Er
{
  private:

  struct relation{
                std::string type;
                Er *other;
            };
  struct atribut{
                std::string name;
                T value;
            };
  std::vector<relation> *relations;
  std::vector<atribut> *atributs;
  int i_at;
  int i_re;
 public:
  Er()
  {
      i_at=0;
      i_re=0;
      relations=new std::vector<relation>;
      atributs=new std::vector<atribut>;
  }

  ~Er() {
     if (relations)
        delete[] relations;
     if (atributs)
        delete[] atributs;
  }

  int insert_atribut(std::string name, T *value)
  {
    atributs->push_back(atribut());
    atributs->at(i_at).name=name;
    atributs->at(i_at).value=*value;
    i_at++;
    return 0;
  }

  int insert_relation(std::string type,Er *other)
  {
    relations->push_back(relation());
    relations->at(i_re).type=type;
    relations->at(i_re).other=other;
    i_re++;
    return 0;
  }

  int return_amount_atributs()
  {
      return i_at;
  }

  int return_amount_relations()
  {
      return i_re;
  }

  std::string return_atribut_name(int i)
  {
      return atributs->at(i).name;
  }

  T return_atribut_value(int i)
  {
      return atributs->at(i).value;
  }

  Er* return_relation(int i)
  {
      return relations->at(i).other;
  }

  std::string return_relation_type(int i)
  {
      return relations->at(i).type;
  }
};


#endif // ER_DIAGRAM_H

