#include "head.h"

bool reverseList(linkList list){
    // 1. 安全性检查：链表必须存在
    if(list == NULL)
        return false;
    
    // 2. 获取第一个数据节点作为"锚点"
    //    p将始终指向原始的第一个节点，这个节点最终会成为反转后的最后一个节点
    LNode* p = list->next;
    
    // 3. 核心反转逻辑
    //    循环条件：p->next != NULL，即还有节点需要移动到p前面
    //    注意：如果链表为空（p==NULL）或只有一个节点（p->next==NULL），循环不会执行
    while(p->next != NULL){
        // 3.1 temp指向需要移到头部的节点（当前p的后继）
        //     第一次循环：temp是原始第二个节点
        //     第二次循环：temp是原始第三个节点
        //     ...以此类推
        LNode* temp = p->next;
        
        // 3.2 锚点p跳过temp，直接连接temp的后继
        //     保持p始终指向原始第一个节点，但更新它的next指向
        p->next = temp->next;
        
        // 3.3 将temp节点插入到链表头部
        //     temp->next指向当前链表的第一个数据节点
        temp->next = list->next;
        
        // 3.4 头结点指向temp，temp成为新的第一个节点
        list->next = temp;
        
        // 3.5 此时temp已被移到头部，p->next自动指向下一个需要移动的节点
        //     不需要显式移动p，p保持指向原始第一个节点
    }
    
    // 4. 返回成功
    //    循环结束时，所有p后面的节点都已被移到p前面
    //    链表完成反转，原始第一个节点变成最后一个节点
    return true;
}

//解法2：p = list->next,list->next = NULL 然后遍历p去头插法list
//解法3：三指针法

linkList reverseList2(linkList list){
    if (list == NULL || list->next == NULL) 
        return list;
    LNode *pre,*p = list->next,*r = p->next;
    p->next = NULL;
    while(r!=NULL){
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;

    }//先形成 pre p r,三个指针对应三个节点
    list->next = p;//处理最后一个
    return list;
}