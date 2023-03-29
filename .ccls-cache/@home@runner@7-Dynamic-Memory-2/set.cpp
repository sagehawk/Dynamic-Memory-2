#include "set.h"

#include <iostream>
#include <cctype>

#include "srchsort.h"
#include "input.h"

using namespace std;

long Set::find(const long item) const
{
   return bin_search(the_set, 0, cur_elem-1, item);
}

void Set::arrange(void)
{
   sort(the_set, 0, cur_elem-1);
   return;
}


bool Set::add_elem(const long item)
{
   bool worked = false;
   if (cur_elem < MAX_SET)
   {
      worked = true;
      the_set[cur_elem++] = item;
      if (cur_elem > 1)
      {
         arrange();
         rem_dupl();
      }
   }
   return worked;
}

void Set::rem_elem(const long item, const long from_where)
{
   for (long i = from_where; i < (cur_elem-1); i++)
   {
      the_set[i] = the_set[i+1];
   }
   cur_elem--;
   return;
}


Set::Set(void) : cur_elem(0)
{
}


bool Set::ismember(const long item) const
{
   return (find(item) >= 0);
}


bool Set::union_with(const Set & set)
{
   for (long i = 0; i < set.cur_elem; i++)
   {
      add_elem(set.the_set[i]);
   }
   return true;
}

bool Set::difference(const Set & set)
{
   for (long i = 0; i < set.cur_elem; i++)
   {
      rem_elem(set.the_set[i]);
   }
   return true;
}

// this is TERRIBLY inefficient!!!  MUST fix someday...
bool Set::intersection(const Set & set)
{
   Set t(*this);   // my twin?
   t.difference(set);    // remove common parts
   difference(t);        // now remove rest from me
   return true;
}

bool Set::rem_elem(const long item)
{
   long at;
   if ((at = find(item)) >= 0)
   {
      rem_elem(item, at);
   }
   return (at >= 0);
}


void Set::output(ostream & out) const
{
   long i;
   out << " { ";
   for (i = 0; i < cur_elem; i++)
   {
      out << the_set[i] << "  ";
      if (((i+1)%7) == 0)
      {
         out << endl << "   ";
      }
   }
   out << "}";
   if ((i%7) == 0)
   {
      out << endl;
   }
   return;
}

void Set::input(istream & in)
{
   char brace;
   long i;
   in >> brace;
   i = 0;
   while ((i < MAX_SET) && !in.eof() && isdigit(peek(in)))
   {
      in >> the_set[i++];
   }
   in >> brace;
   cur_elem = i;
   arrange();
   rem_dupl();
   return;
}

void Set::rem_dupl(void)
{
   long i = 0;
   while (i < (cur_elem-1))
   {
      if (the_set[i] == the_set[i+1])
      {
         rem_elem(the_set[i], i);
      }
      else
      {
         i++;
      }
   }
   return;
}

bool Set::full(void) const
{
    return (cur_elem == MAX_SET);
}