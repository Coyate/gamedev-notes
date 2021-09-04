
fn int32_to_ip(int: u32) -> String {
    let mut i = int;
    let mut s = (i % 256).to_string();
    i /= 256;
    s = (i % 256).to_string() + "." + &s;
    i /= 256;
    s = (i % 256).to_string() + "." + &s;
    i /= 256;
    s = i.to_string() + "." + &s;
    s
}

use itertools::Itertools;
fn int32_to_ip1(int: u32) -> String {
    int.to_be_bytes().iter().join(".")
}

use std::net::Ipv4Addr;
fn int32_to_ip2(int: u32) -> String {
    Ipv4Addr::from(int).to_string()
}

fn int32_to_ip3(int: u32) -> String {
    let a = (int & 0xFF000000) >> 24;
    let b = (int & 0x00FF0000) >> 16;
    let c = (int & 0x0000FF00) >> 8;
    let d = (int & 0x000000FF);
    format!("{}.{}.{}.{}", a, b, c, d)
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn basic() {
        assert_eq!(int32_to_ip(2154959208), "128.114.17.104");
        assert_eq!(int32_to_ip(2149583361), "128.32.10.1");
        assert_eq!(int32_to_ip(0), "0.0.0.0");
    }
}
