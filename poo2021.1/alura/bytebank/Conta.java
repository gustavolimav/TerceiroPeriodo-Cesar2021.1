public class Conta {
    // Four attributes
    double balance;
    int agency;
    int number;
    Cliente holder;

    // Method
    public void deposit(double value) {
        this.balance += value;
    }

    public boolean saca(double value) {
        if(this.balance >= value) {
            this.balance -= value;
            return true;
        } else {
            return false;
        }
    }

    public boolean transfer(double value, Conta destine) {
        if(this.balance >= value) {
            this.balance -= value;
            destine.deposit(value);
            return true;
        }
        return false;
    }   

}
