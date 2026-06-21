package PROJECT;

class NoodleDish {
    enum DishStatus {
        AVAILABLE, UNAVAILABLE
    }
    private String name;
    private double price;
    private DishStatus status;

    public NoodleDish(String name, double price, DishStatus status) {
        this.name = name;
        this.price = price;
        this.status = status;
    }

    public void setStatus(DishStatus status) {
        this.status = status;
        System.out.println("Dish " + name + " is now " + status);
    }

    public DishStatus getStatus() {
        return status;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return name + " - RM" + price + " - " + status;
    }
}
