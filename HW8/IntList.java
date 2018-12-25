public class IntList implements MyList {
	public int data;
	public IntList nextNode;
	
	public IntList(int value) {
		this.data = 0;
	}

	public IntList(IntList n, int data) {
		this.nextNode = n;
		this.data = data;
	}
	public int getData() {
		return this.data;
	}
	public IntList next() {
		return this.nextNode;
	}
	public void printNode() {
		System.out.print("IntList Node, data is: "+getData());
	}
}