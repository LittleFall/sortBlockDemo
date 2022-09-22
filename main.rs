impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        for n in 1..=n {
            if n%3 == 0 && n%5 == 0 {
                res.push(String::from("FizzBuzz"));
            } else if n%3 == 0 {
                res.push(String::from("Fizz"));
            } else if n%5 == 0 {
                res.push(String::from("Buzz"));
            } else {
                res.push(n.to_string());
            }
        }
        return res;
    }
}