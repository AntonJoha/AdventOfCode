use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;


fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}


fn main() {
    if let Ok(lines) = read_lines("file") {
    
        let mut max : Vec<u128> = vec!{0,0,0};
        let mut current: u128 = 0;
        for line in lines {
            if let Ok(l) = line {
                if l == "".to_string() {
                    
                    if current > max[0] {
                        max[2] = max[1];
                        max[1] = max[0];
                        max[0] = current;
                    }
                    else if current > max[1] {
                        max[2] = max[1];
                        max[1] = current;
                    }
                    else if current > max[2] {
                        max[2] = current;
                    }
                    current = 0;
                }
                else {
                    current += l.parse::<u128>().unwrap();
                }
            }
        }

        if current > max[0] {
            max[2] = max[1];
            max[1] = max[0];
            max[0] = current;
        }
        else if current > max[1] {
            max[2] = max[1];
            max[1] = current;
        }
        else if current > max[2] {
            max[2] = current;
        }

        println!("{}, {:?}", max[0] + max[1] + max[2], max);

    }


}
