怎么用两个堆栈实现一个队列?


栈的特点是后进先出，队列的特点是先进先出。所以，用两个栈s1和s2模拟一个队列时，
s1作输入栈，逐个元素压栈，以此模拟队列元素的入队。当需要出队时，将栈s1退栈并
逐个压入栈s2中，s1中最先入栈的元素，在s2中处于栈顶。s2退栈，相当于队列的出队，
实现了先进先出。显然，只有栈s2为空且s1也为空，才算是队列空。
[算法讨论]算法中假定栈s1和栈s2容量相同。出队从栈s2出，当s2为空时，若s1不空，
则将s1倒入s2再出栈。入队在s1，当s1满后，若s2空，则将s1倒入s2，之后再入队。
因此队列的容量为两栈容量之和。元素从栈s1倒入s2，必须在s2空的情况下才能进行，
即在要求出队操作时，若s2空，则不论s1元素多少（只要不空），就要全部倒入s2中。
下面两个方法的思路是一致的，只是一个是基于进栈与队列相同一个基于出栈与队列相同。
