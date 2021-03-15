public class Conta {
    // Four attributes
    private double balance;
    private int agency;
    private int number;
    private Cliente holder;

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

    public double getbalance() {
        return this.balance;        
    }

    public int getNumber() {
        return this.number;
    }

    public void setNumber(int newNumber) {
        this.number = newNumber;
    }

    public int getAgency() {
        return this.agency;
    }

    public void setHolder(Cliente holder) {
        this.holder = holder;
    }

    public Cliente getHolder() {
        return holder;
    }

}
