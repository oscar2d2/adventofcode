defmodule Q4 do
  def md5(s) do
    Base.encode16(:erlang.md5(s), case: :lower)
  end

  def solve(secret, n) do
    #flag = md5(secret <> Integer.to_string(n)) |> String.starts_with? "00000"
    flag = md5(secret <> Integer.to_string(n)) |> String.starts_with? "000000"

    case flag do
      true -> n
      _ -> solve(secret, n+1) 
    end
  end
end

IO.puts Q4.solve("ckczppom",1)
