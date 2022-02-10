
import java.util.LinkedList;
import java.util.Queue;

public class MyStack {

    Queue queue1;
    Queue queue2;

    public MyStack() {

        queue1 = new LinkedList();
        queue2 = new LinkedList();
    }

    public void push(int x) {

        queue2.offer(x);
        while(!queue1.isEmpty()){
            queue2.offer(queue1.poll());
        }

        Queue temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }

    public int pop() {
        return (int) queue1.poll();

    }

    public int top() {
        return (int) queue1.peek();
    }

    public boolean empty() {
        return queue1.isEmpty();
    }
}
