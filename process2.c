#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t Queue;            //opec data type
struct mq_attr Queue_attr;        //defining msg que structure
char buffer[128];                   // buffer for rx msg
int prio;                           // priority  for multiple queues

int main()
{
    Queue_attr.mq_flags =0;
    Queue_attr.mq_maxmsg = 4;
    Queue_attr.mq_msgsize = 128;
    Queue_attr.mq_curmsgs = 0;

    Queue = mq_open("/cdacmq",O_RDONLY | O_CREAT,S_IRUSR | S_IWUSR);

    mq_receive(Queue, buffer ,128,&prio);
    printf("Got the msg : %s \n with Msg priority :%d\n",buffer , prio); //printing  buffer
    printf("msg length is %d\n",strlen(buffer));
    mq_close(Queue);                    //closing the msg queue
    return 0;
}