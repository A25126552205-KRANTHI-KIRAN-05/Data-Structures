#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#define MAX 5
int stack[MAX];
int top = -1;
/* check if stack is full */
int isFull() {
return top == MAX - 1;
}
/* check if stack is empty */
int isEmpty() {

Data Structures — Stack Implementations

Page 2 of 2

return top == -1;
}
/* push an element onto the stack */
void push(int val) {
if (isFull()) {
printf(&quot;Stack Overflow\n&quot;);
return;
}
stack[++top] = val;
printf(&quot;Pushed %d\n&quot;, val);
}
/* pop an element from the stack */
void pop() {
if (isEmpty()) {
printf(&quot;Stack Underflow\n&quot;);
return;
}
printf(&quot;Popped %d\n&quot;, stack[top--]);
}
/* view the top element without removing it */
void peek() {
if (isEmpty()) {
printf(&quot;Stack is empty\n&quot;);
return;
}
printf(&quot;Top element: %d\n&quot;, stack[top]);
}
/* print all elements of the stack */
void display() {
if (isEmpty()) {
printf(&quot;Stack is empty\n&quot;);
return;
}
printf(&quot;Stack (bottom -&gt; top): &quot;);
for (int i = 0; i &lt;= top; i++)
printf(&quot;%d &quot;, stack[i]);
printf(&quot;\n&quot;);
}
int main() {
int choice, val;
while (1) {
printf(&quot;\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n&quot;);
printf(&quot;Enter choice: &quot;);
scanf(&quot;%d&quot;, &amp;choice);
switch (choice) {
case 1:
printf(&quot;Enter value to push: &quot;);
scanf(&quot;%d&quot;, &amp;val);
push(val);
break;
case 2:
pop();
break;

Data Structures — Stack Implementations

Page 3 of 2

case 3:
peek();
break;
case 4:
display();
break;
case 5:
exit(0);
default:
printf(&quot;Invalid choice\n&quot;);
}
}
return
