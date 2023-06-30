 Node *head1 = head;
     Node *head2 = mid->next;
     while (head2 != NULL)
     {
         if (head1->data != head2->data)
         {
             cout << head->data << " " << head2->data << endl;
             return false;
         }
         head1 = head1->next;
         head2 = head2->next;
     }
     temp = mid->next;
     mid->nex