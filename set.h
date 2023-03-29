#ifndef SET_HEADER_INCLUDED
#define SET_HEADER_INCLUDED

#include <iostream>

const long MAX_SET = 50;

class Set
{
   long the_set[MAX_SET];
   long cur_elem;

   long find(const long item) const;
   void arrange(void);
   void rem_elem(const long item, const long fromwhere);
   void rem_dupl(void);

public:
   Set(void);

   bool ismember(long item) const;

   bool union_with(const Set & set);
   bool intersection(const Set & set);
   bool difference(const Set & set);
   bool add_elem(const long item);
   bool rem_elem(const long item);

   bool full(void) const;

   void input(std::istream & in);
   void output(std::ostream & out) const;
};

#endif