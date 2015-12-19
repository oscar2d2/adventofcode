defmodule Q6 do
  def format(["turn", "on", fromx, fromy, _, tox, toy]) do
    [:on, fromx, fromy, tox, toy]
  end
  def format(["turn", "off", fromx, fromy, _, tox, toy]) do
    [:off, fromx, fromy, tox, toy]
  end
  def format(["toggle", fromx, fromy, _, tox, toy]) do
    [:toggle, fromx, fromy, tox, toy]
  end
  def to_int([action | xs]) do
    [action | Enum.map(xs, &String.to_integer(&1))]
  end
  def form_grid(m,n,val) do 
     List.duplicate(val, n) |> List.duplicate(m)
  end 
  def updateRow(row, _, fx, tx) when fx > tx, do: row
  #  def updateRow(row, :on, fx, tx) do
  #    row |> List.replace_at(fx, 1) |> updateRow(:on, fx + 1, tx)
  #  end
  #  def updateRow(row, :off, fx, tx) do
  #    row |> List.replace_at(fx, 0) |> updateRow(:off, fx + 1, tx)
  #  end
  #  def updateRow(row, :toggle, fx, tx) do
  #    newVal = 1 - Enum.at(row, fx)
  #    row |> List.replace_at(fx, newVal) |> updateRow(:toggle, fx + 1, tx)
  def updateRow(row, :on, fx, tx) do
    brightness = Enum.at(row, fx) + 1
    row |> List.replace_at(fx, brightness) |> updateRow(:on, fx + 1, tx)
  end
  def updateRow(row, :off, fx, tx) do
    brightness = max(Enum.at(row, fx) - 1, 0)
    row |> List.replace_at(fx, brightness) |> updateRow(:off, fx + 1, tx)
  end
  def updateRow(row, :toggle, fx, tx) do
    brightness = Enum.at(row, fx) + 2
    row |> List.replace_at(fx, brightness) |> updateRow(:toggle, fx + 1, tx)
  end
  def process(grid, [_, _, fy, _, ty]) when fy > ty, do: grid
  def process(grid, [action , fx, fy, tx, ty]) do
    newRow = Enum.at(grid, fy) |> updateRow(action, fx, tx)

    List.replace_at(grid, fy, newRow)
    |> process([action, fx, fy + 1, tx, ty])
  end 
  def sum(grid) do 
    grid |> Enum.map(&Enum.sum(&1)) |> Enum.sum() 
  end
  def run() do
    {:ok, file} = File.open("6_input.txt", [:read])
    IO.read(file, :all) 
    |> String.split("\n", trim: true)
    |> Enum.map(fn(x) -> String.split(x, [" ", ","]) end)
    |> Enum.map(fn(x) -> format(x) end)
    |> Enum.map(&to_int(&1))
    |> List.foldl(form_grid(1000,1000,0), fn (x, acc) -> process(acc, x) end)
    |> sum()
  end
end

IO.inspect :calendar.local_time()
IO.inspect Q6.run
IO.inspect :calendar.local_time()
