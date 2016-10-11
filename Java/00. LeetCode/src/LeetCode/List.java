/**
 * 
 */
package LeetCode;

/**
 * @author Roman
 *
 */
public class List
{
	private ListNode dummy = new ListNode(0);
	private ListNode last = dummy;
	
	public List() {}
	
	public List(int... values)
	{
		for (int val : values) {
			addLast(val);
		}
	}
	
	public List(ListNode head)
	{
		dummy.next = head;
		while (last.next != null)
			last = last.next;
	}
	
	public ListNode head() { 
		return dummy.next;
	}
	public ListNode last() {
		return last != dummy ? last : null;
	}
	
	public void clear() {
		dummy.next = null;
	}
	
	public void addLast(int val)
	{
		last = last.next = new ListNode(val);
	}
	
	public void addHead(int val)
	{
		ListNode node = new ListNode(val);
		node.next = dummy.next;
		dummy.next = node;
	}
	
	//@Override
	public boolean equals(Object obj)
	{
		ListNode node1 = head();
		ListNode node2 = null;
		
		if (obj instanceof List) {
			node2 = ((List)obj).head();
		}
		else if (obj instanceof ListNode) {
			node2 = (ListNode)obj;
		}
		
		while (node1 != null && node2 != null) {
			if (node1.val != node2.val)
				return false;
			node1 = node1.next;
			node2 = node2.next;
		}
	
		return node1 == node2;
	}	
}
