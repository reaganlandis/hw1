#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

 void ULListStr::push_front(const std::string& val){
   size_++;
   if(head_ == NULL){
     head_ = new Item();
     tail_ = head_;
     head_->last = 10;
     head_->first = 9;
     head_->val[head_->first] = val;
   }
   else if(head_->first == 0){
     Item* newNode = new Item(); 
     newNode->next = head_;
     head_->prev = newNode;
     head_ = newNode;
     head_->first = 9;
     head_->last = 10;
     head_->val[head_->first] = val;
   }
   else{
     head_->first --;
     head_->val[head_->first] = val;
   }
 }

void ULListStr::pop_front(){
  if(size_ == 1){
    head_ = NULL;
    tail_ = NULL;
  }
  else if(size_ == 0){
    return;
  }
  else if(head_->first == 9){
    Item* oldNode = head_;
    head_ = head_->next;
    delete oldNode;
    head_->prev = NULL;
  }
  else{
    head_->first ++;
  }
  size_ --;
}

void ULListStr::push_back(const std::string& val){
   size_++;
   if(tail_ == NULL){
     head_ = new Item();
     tail_ = head_;
     tail_->last = 1;
     tail_->first = 0;
     tail_->val[tail_->first] = val;
   }
   else if(tail_->last == 10){
     Item* newNode = new Item();
     newNode->prev = tail_;
     tail_->next = newNode;
     tail_ = newNode;
     tail_->first = 0;
     tail_->last = 1;
     tail_->val[tail_->first] = val;
   }
   else{
     tail_->val[tail_->last] = val;
     tail_->last ++;
   }
}

void ULListStr::pop_back(){
  if(size_==1){
    head_ = NULL;
    tail_ = NULL;
  }
  else if(size_ == 0){
    return;
  }
  else if(tail_->last == 1){
    Item* oldNode = tail_;
    tail_ = tail_->prev;
    delete oldNode;
    tail_->next = NULL;
  }
  else{
    tail_->last --;
  }
  size_ --;
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc>= size_) return NULL;
  else{
    Item* temp = head_;
    while(temp->last - temp->first <= loc){
      loc = loc-(temp->last - temp->first);
      temp = temp->next;
    }
    return &temp->val[temp->first + loc];
  }
  
}
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
