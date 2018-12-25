public class LongList implements MyList {
	public long data;
	public LongList nextNode;
	
	public LongList(long value) {
		this.data = 0;
	}

	public LongList(LongList n, long data) {
		this.nextNode = n;
		this.data = data;
	}
	public long getData() {
		return this.data;
	}
	public LongList next() {
		return this.nextNode;
	}
	public void printNode() {
		System.out.print("LongList Node, data is: "+getData());
	}
}