int getSize(ListNode* head)
{
    int count = 0;
    while (head == NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void swapData(ListNode* temp1, ListNode* temp2)
{
    int tmp = temp1->val;
    temp1->val = temp2->val;
    temp2->val = tmp;
}