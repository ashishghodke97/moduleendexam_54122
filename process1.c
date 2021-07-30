#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<mqueue.h>

mqd_t Queue;                // queue defining or queue discriptor
struct mq_attr Queue_attr;  //definging msg queue structure

int main()
{
    Queue_attr.mq_flags = 0;
    Queue_attr.mq_maxmsg = 4;
    Queue_attr.mq_msgsize = 128;
    Queue_attr.mq_curmsgs = 0;

    Queue = mq_open("/cdacmq", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &Queue_attr );

    mq_send(Queue, "massege\n",8,0);

    mq_close(Queue);
return 0;

}