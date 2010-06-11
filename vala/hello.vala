public class Demo.HelloWorld : GLib.Object {
    private int _age = 32;
    
    public int age {
        get { return _age; }
        set { _age = value; }
    }
        
    public HelloWorld () {
    }
    
    public HelloWorld.say_hello (string msg) {
    }

    public static int main(string[] args) {

        stdout.printf("Hello, World\n");

        return 0;
    }
}
