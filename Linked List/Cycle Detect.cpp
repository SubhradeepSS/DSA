bool hasCycle(ListNode *head) {
        ListNode *s=head,*f=head;
        while(s&&f&&f->next){
            s=s->next;
            f=f->next->next;
            if(s==f)
                return true;
        }
        return false;
    }
