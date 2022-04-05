int intersectPoint(Node* head1, Node* head2)
{
  Node* p1 = head1;
  Node* p2 = head2;
  int c1 = 0 , c2 = 0;
  while(p1 or p2)
  {
    if(p1)
    {
      p1=p1->next;
      c1++;
    }
    
    if(p2)
    {
      p2=p2->next;
      c2++;
    }
  }
  
  int diff= abs(c1-c2);
  p1=head1;
  p2=head2;
  
  if(c1>c2)
  {
    for(int i=0;i<diff;i++) p1=p1->next;
  }
  else 
  {
    for(int i=0;i<diff;i++) p2=p2->next;
  }
  
  while(p1 != p2)
  {
    p1=p1->next;
    p2=p2->next;
  }
  
  if(p1) return p1->data;
  return -1;
}