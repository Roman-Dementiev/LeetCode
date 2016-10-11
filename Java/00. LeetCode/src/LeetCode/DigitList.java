/**
 * 
 */
package LeetCode;

import java.math.BigInteger;

/**
 * @author Roman
 *
 */
public class DigitList extends List
{
	protected boolean reversed;
	
	public DigitList()
	{
	}

	public DigitList(ListNode head)
	{
		this(head, false);
	}
	
	public DigitList(ListNode head, boolean reversed)
	{
		super(head);
		this.reversed = reversed;
		
		for (ListNode node = head; head != null; head = head.next) {
			if (node.val < 0 || node.val > 9) {
				clear();
				return;
			//	throw new Exception("Not a digit");
			}
		}
	}
	
	public DigitList(String str) throws Exception
	{
		this(str, false);
	}
	
	public DigitList(String str, boolean reversed)
	{
		this.reversed = reversed;
		if (str == null || str.isEmpty())
			return;
		
		for (int i = 0; i < str.length(); i++) {
			char ch = str.charAt(i);
			if (ch < '0' || ch > '9') {
				clear();
				return;
			//	throw new Exception("Not a digit");
			}
			
			addLast(ch-'0');
		}
		
	}
	
	public DigitList(long value, boolean reversed)
	{
		this.reversed = reversed;
		if (value < 0) {
			return;
		//	throw new Exception("Negative value");
		}
		
		if (value == 0) {
			addLast(0);
			return;
		}
		
		do {
			int digit = (int)(value % 10);
			value /= 10;
			if (reversed) {
				addLast(digit);
			} else {
				addHead(digit);
			}
		}
		while (value > 0);
	}

	public DigitList(BigInteger value, boolean reversed)
	{
		this.reversed = reversed;
		int cmp = value.compareTo(BigInteger.ZERO);
		if (cmp < 0) {
			return;
		//	throw new Exception("Negative value");
		}
		
		if (cmp == 0) {
			addLast(0);
			return;
		}
		
		do {
			BigInteger[] dr = value.divideAndRemainder(BigInteger.TEN);
			value = dr[0];
			int digit = dr[1].intValue();
			if (reversed) {
				addLast(digit);
			} else {
				addHead(digit);
			}
			cmp = value.compareTo(BigInteger.ZERO);
		}
		while (cmp > 0);
	}

	
	public BigInteger getValue()
	{
		BigInteger value = BigInteger.ZERO;
		
		if (reversed) {
			BigInteger m = BigInteger.ONE;
			for (ListNode node = head(); node != null; node = node.next) {
				value = value.add(m.multiply(BigInteger.valueOf(node.val)));
				m = m.multiply(BigInteger.TEN);
			}
			
		} else {
			for (ListNode node = head(); node != null; node = node.next) {
				value = value.multiply(BigInteger.TEN);
				value = value.add(BigInteger.valueOf(node.val));
			}
		}
		
		return value;
	}
}
