#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
struct Node {
int data;
struct Node *next;
struct Node *prev;
};
struct Node *head = NULL;
void insertBeginning(int value) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode-&gt;data = value;
if (head == NULL) {
newNode-&gt;next = newNode;
newNode-&gt;prev = newNode;
head = newNode;
return;

}
struct Node *last = head-&gt;prev;
newNode-&gt;next = head;
newNode-&gt;prev = last;
head-&gt;prev = newNode;
last-&gt;next = newNode;
head = newNode;
}
void insertEnd(int value) {
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode-&gt;data = value;
if (head == NULL) {
newNode-&gt;next = newNode;
newNode-&gt;prev = newNode;
head = newNode;
return;
}
struct Node *last = head-&gt;prev;
newNode-&gt;next = head;
newNode-&gt;prev = last;
last-&gt;next = newNode;
head-&gt;prev = newNode;
}
void insertPosition(int value, int pos) {
if (pos == 1) {
insertBeginning(value);
return;
}
struct Node *temp = head;
for (int i = 1; i &lt; pos - 1; i++) {
temp = temp-&gt;next;
}
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode-&gt;data = value;
newNode-&gt;next = temp-&gt;next;
newNode-&gt;prev = temp;
temp-&gt;next-&gt;prev = newNode;
temp-&gt;next = newNode;
}
void deleteBeginning() {
if (head == NULL) {
printf(&quot;List is empty\n&quot;);
return;

}
if (head-&gt;next == head) {
free(head);
head = NULL;
return;
}
struct Node *last = head-&gt;prev;
struct Node *temp = head;
head = head-&gt;next;
head-&gt;prev = last;
last-&gt;next = head;
free(temp);
}
void deleteEnd() {
if (head == NULL) {
printf(&quot;List is empty\n&quot;);
return;
}
if (head-&gt;next == head) {
free(head);
head = NULL;
return;
}
struct Node *last = head-&gt;prev;
struct Node *secondLast = last-&gt;prev;
secondLast-&gt;next = head;
head-&gt;prev = secondLast;
free(last);
}
void deletePosition(int pos) {
if (head == NULL) {
printf(&quot;List is empty\n&quot;);
return;
}
if (pos == 1) {
deleteBeginning();
return;
}
struct Node *temp = head;
for (int i = 1; i &lt; pos; i++) {
temp = temp-&gt;next;
}

if (temp == head) {
printf(&quot;Invalid position\n&quot;);
return;
}
temp-&gt;prev-&gt;next = temp-&gt;next;
temp-&gt;next-&gt;prev = temp-&gt;prev;
free(temp);
}
void display() {
if (head == NULL) {
printf(&quot;List is empty\n&quot;);
return;
}
struct Node *temp = head;
printf(&quot;List: &quot;);
do {
printf(&quot;%d &quot;, temp-&gt;data);
temp = temp-&gt;next;
} while (temp != head);
printf(&quot;\n&quot;);
}
int main() {
int choice, value, pos;
while (1) {
printf(&quot;\n--- Circular Doubly Linked List Menu ---\n&quot;);
printf(&quot;1. Insert at Beginning\n&quot;);
printf(&quot;2. Insert at End\n&quot;);
printf(&quot;3. Insert at Position\n&quot;);
printf(&quot;4. Delete from Beginning\n&quot;);
printf(&quot;5. Delete from End\n&quot;);
printf(&quot;6. Delete from Position\n&quot;);
printf(&quot;7. Display\n&quot;);
printf(&quot;8. Exit\n&quot;);
printf(&quot;Enter your choice: &quot;);
scanf(&quot;%d&quot;, &amp;choice);
switch (choice) {
case 1:
printf(&quot;Enter value: &quot;);
scanf(&quot;%d&quot;, &amp;value);
insertBeginning(value);
break;
case 2:
printf(&quot;Enter value: &quot;);
scanf(&quot;%d&quot;, &amp;value);
insertEnd(value);
break;
case 3:
printf(&quot;Enter value and position: &quot;);
scanf(&quot;%d %d&quot;, &amp;value, &amp;pos);

insertPosition(value, pos);
break;
case 4:
deleteBeginning();
break;
case 5:
deleteEnd();
break;
case 6:
printf(&quot;Enter position: &quot;);
scanf(&quot;%d&quot;, &amp;pos);
deletePosition(pos);
break;
case 7:
display();
break;
case 8:
exit(0);
default:
printf(&quot;Invalid choice\n&quot;);
}
}
return 0;
}
