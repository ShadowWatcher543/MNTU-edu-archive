function processProducts(products) {
    // 1. Фільтруємо товари в наявності та витягуємо їхні імена
    const inStockProducts = products.filter(p => p.inStock);
    const available = inStockProducts.map(p => p.name);

    // 2. Рахуємо суму цін товарів у наявності через reduce
    const totalPrice = inStockProducts.reduce((acc, p) => acc + p.price, 0);

    // 3. Шукаємо найдешевший товар серед наявних з обробкою крайнього випадку
    let cheapest = undefined;
    if (inStockProducts.length > 0) {
        let cheapestProduct = inStockProducts[0];
        for (let i = 1; i < inStockProducts.length; i++) {
            if (inStockProducts[i].price < cheapestProduct.price) {
                cheapestProduct = inStockProducts[i];
            }
        }
        cheapest = cheapestProduct.name;
    }

    // 4. Формуємо повний прайс-лист для всіх товарів через map
    const priceList = products.map(p => p.name + " — " + p.price + " грн");

    return { available, totalPrice, cheapest, priceList };
}

const products = [
    { name: "Чай", price: 50, inStock: true },
    { name: "Кава", price: 120, inStock: false },
    { name: "Цукор", price: 30, inStock: true }
];

console.log(processProducts(products))
// {
// available: ["Чай", "Цукор"],
// totalPrice: 80,
// cheapest: "Цукор",
// priceList: ["Чай — 50 грн", "Кава — 120 грн", "Цукор — 30 грн"]
// }